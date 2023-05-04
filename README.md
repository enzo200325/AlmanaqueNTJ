# AlmanaqueNTJ

Repositório de códigos para programação competitiva do NTJ com latex copiado da UFMG.
Ainda em desenvolvimento.

### Pasta `codigos`

Todas as implementações estão nessa pasta.

### Pasta `latex`

Aqui estão os scripts necessários para gerar o latex e o pdf do Almanaque, com base nos códigos que estão na pasta `codigos`. O arquivo `almanaque.tex` também está nessa pasta.

Aqui também estão os arquivos `INICIO_README.md` e `INICIO_LATEX.tex`, que são usados como cabeçalho para os arquivos `README.md` e `almanaque.tex`, respectivamente. Se quiser alterar o README ou as configurações do latex, edite sempre esses arquivos.

Após qualquer alteração nos códigos ou nos arquivos `INICIO*`, basta rodar o `update.sh`, que vai atualizar o `.tex` e o `.pdf` do Almanaque, bem como atualizar o README.

OBS: Antes de rodar o update.sh, rode os seguintes comandos para instalar o latex:

```
sudo apt install texlive-full
sudo apt install rubber
```

### Pasta `pdf`

Aqui está o `.pdf` do Almanaque.

## CONTEÚDOS


### Problemas

- [Kth digito na string infinita de digitos](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Problemas/infinite_digit_string.cpp)

### Estruturas

- [Fenwick Tree](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Estruturas/fenwick.cpp)

### Grafos

- [Bridges e Edge Biconnected Components](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Grafos/bridges.cpp)

### Extra

- [Template C++](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/template.cpp)
- [Config do Vim](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/vimrc)
- [Rand C++](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/rand.cpp)
- [Template de debug simples](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/debug.cpp)
- Stress Test
	- [Script de stress test](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/Stress Test/stress.sh)
	- [Gerador aleatorio de inteiros em (l, r)](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/codigos/Extra/Stress Test/gen.cpp)
