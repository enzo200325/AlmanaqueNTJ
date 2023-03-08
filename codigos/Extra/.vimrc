set number
set nohls
set ai

set belloff=all

syntax on
filetype plugin indent on

set ts=4
set sw=4
set expandtab
set noshiftround

set showmode
set showcmd

" bracket remap
inoremap {} {}<Left><Return><Up><End><Return> 

" bracket translator
nnoremap ç :g/{/normal kJx<return>
nnoremap Ç :g/{/normal $xo{<return>
