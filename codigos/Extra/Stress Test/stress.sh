// Script de stress test

set -e
g++-13 -O2 code.cpp -o code
g++-13 -O2 brute.cpp -o brute
g++-13 -O2 gen.cpp -o gen

for((i = 1; ; ++i)); do
    ./gen > in
    ./code < in > myout
    ./brute < in > out
    diff myout out > /dev/null || break
    echo "OK: "  $i
done

echo "WA:"
cat in
echo "Myout:"
cat myout
echo "Out:"
cat out
