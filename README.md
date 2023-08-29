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


### Strings

- [Automato de Aho Corasick](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%53%74%72%69%6E%67%73/%61%68%6F%63%6F%72%61%73%69%63%6B.%63%70%70)
- [Hashing](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%53%74%72%69%6E%67%73/%68%61%73%68%69%6E%67.%63%70%70)

### Problemas

- [Kth digito na string infinita de digitos](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%50%72%6F%62%6C%65%6D%61%73/%69%6E%66%69%6E%69%74%65%5F%64%69%67%69%74%5F%73%74%72%69%6E%67.%63%70%70)

### Estruturas

- SegTree
	- [Segment Tree Beats](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%73%74%72%75%74%75%72%61%73/%53%65%67%54%72%65%65/%73%65%67%62%65%61%74%73.%63%70%70)
- [Fenwick Tree](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%73%74%72%75%74%75%72%61%73/%66%65%6E%77%69%63%6B.%63%70%70)

### Grafos

- [Pontos de articulacao](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%47%72%61%66%6F%73/%70%6F%6E%74%6F%73%5F%64%65%5F%61%72%74%69%63%75%6C%61%63%61%6F.%63%70%70)
- [Bridges e Edge Biconnected Components](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%47%72%61%66%6F%73/%62%72%69%64%67%65%73.%63%70%70)
- [Binary Lifting](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%47%72%61%66%6F%73/%62%69%6E%61%72%79%5F%6C%69%66%74%69%6E%67.%63%70%70)

### Matematica

- [Pollard Rho](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%4D%61%74%65%6D%61%74%69%63%61/%70%6F%6C%6C%61%72%64%72%68%6F.%63%70%70)
- [Fast Fourier Transform](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%4D%61%74%65%6D%61%74%69%63%61/%66%66%74.%63%70%70)
- [Crivo de Eratostenes ](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%4D%61%74%65%6D%61%74%69%63%61/%73%69%65%76%65.%63%70%70)

### Extra

- [Template C++](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%74%65%6D%70%6C%61%74%65.%63%70%70)
- [Custom Hash](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%63%75%73%74%6F%6D%5F%68%61%73%68.%63%70%70)
- [Config do Vim](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%76%69%6D%72%63)
- [Rand C++](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%72%61%6E%64.%63%70%70)
- [Template de debug simples](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%64%65%62%75%67.%63%70%70)
- [Mint](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%6D%69%6E%74.%63%70%70)
- [Script pra rodar C++](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%72%75%6E)
- Stress Test
	- [Script de stress test](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%53%74%72%65%73%73%20%54%65%73%74/%73%74%72%65%73%73.%73%68)
	- [Gerador aleatorio de inteiros em [l, r]](https://github.com/enzo200325/AlmanaqueNTJ/blob/master/%63%6F%64%69%67%6F%73/%45%78%74%72%61/%53%74%72%65%73%73%20%54%65%73%74/%67%65%6E.%63%70%70)
