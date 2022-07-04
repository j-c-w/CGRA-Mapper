#!/bin/zsh

typeset -a plot_only
zparseopts -D -E -- -plot-only=plot_only

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <Output Folder from the run_all_benchmarks.sh script>"
    exit 1
fi

# Keep runtime reasonable -- just sample from the output files
number_of_files=100

if [[ ${#plot_only} == 0 ]]; then
    basefolder=$1

    # The creates three sets of compile times: for the no rewriter, for the EGraphs rewriter and for the traditional rewriter.
    # We don't actually have to plot them all --- since all we are trying
    # to demonstrate is that Flex is fast enough to be useful
    typeset -a egraph_successes
    typeset -a egraph_fails
    fileno=0
    for file in $(find $basefolder -name "*rewriter.out*" | sort -z); do
        fileno=$((fileno + 1))
        if [[ $fileno -gt $number_of_files ]]; then
            break
        fi
		if [[ ! -f $file ]]; then
			break
		fi
        echo "Looking at file $file"
        # Look for the timeout 60 entries because those correspond to the ones
        # that did not time out.  We also should add the timeouts to the fails.
        for time in $(grep --text $file -e Mapping:success -A7 | grep "timeout 300" | cut -f16 -d' '); do
            egraph_successes+="$time,"
        done
        for time in $(grep --text $file -e Mapping:fail -A7 | grep "timeout 300" | cut -f16 -d' '); do
            egraph_fails+="$time,"
        done
		for time in $(grep --text $file -e "timeout 300" -B7 | grep -v Mapping | grep timeout | grep kernel | cut -f16 -d' '); do
			# There was a bug ---timeotus were not retried with the simple mapper like they
			# shuld have been.
			egraph_fails+="$time,"
		done
		# There seems to have been a bug where the fallback wasn't triggered.
        for time in $(grep --text $file -e 'Rewriter timed out, running without rewriter.'); do
            # These are timeouts --- we fallback to the original
            # OpenCGRA if this happens, but the failure
            # takes 60 seconds.
            # TODO --- figure out a way to make this less bug prone.
            # (i.e. if we change the timeout limit)
            egraph_fails+="300,"
        done
    done

    mkdir -p compile_times
    echo ${egraph_successes[@]} > compile_times/egraph_successful
    echo ${egraph_fails[@]} > compile_times/egraph_fails
fi

# TODO --- get the other compile times also
python plot_compile_times.py compile_times/egraph_successful compile_times/egraph_fails
