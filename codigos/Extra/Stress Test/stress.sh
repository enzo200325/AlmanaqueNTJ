// Script de stress test

set -e
g++ -O2 code.cpp -o code
g++ -O2 brute.cpp -o brute
g++ -O2 gen.cpp -o gen

for((i = 1; ; ++i)); do
    ./gen > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
