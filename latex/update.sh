g++ -std=c++17 -o getlatex codes/getlatex.cpp -O2
g++ -std=c++17 -o updatereadme codes/updatereadme.cpp -O2
./getlatex > almanaque.tex
touch README.md > /dev/null
cp INICIO_README.md README.md
./updatereadme >> README.md
mv README.md ..
rubber -d almanaque
mv almanaque.pdf ../pdf
rm getlatex updatereadme almanaque.aux almanaque.toc almanaque.out
mv almanaque* texfiles
