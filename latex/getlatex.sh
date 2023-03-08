g++ -std=c++17 -o getlatex codes/getlatex.cpp -O2
g++ -std=c++17 -o updatereadme codes/updatereadme.cpp -O2
./getlatex > biblioteca.tex
touch README.md > /dev/null
cp INICIO_README.md README.md
./updatereadme >> README.md
mv README.md ..
rubber -d biblioteca
mv biblioteca.pdf ../pdf
rm getlatex updatereadme biblioteca.aux biblioteca.toc biblioteca.out
mv biblioteca* texfiles
