if ! test -f build-number.txt; then echo 0 > build-number.txt; fi
echo $(($(cat build-number.txt) + 1)) > build-number.txt
