" vim-plug install:
" mkdir -p ~/.vim/autoload && curl \
" https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim \
" > ~/.vim/autoload/plug.vim

call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree', { 'on' : 'NERDTreeToggle' }
Plug 'scrooloose/nerdcommenter'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'jiangmiao/auto-pairs'
Plug 'othree/html5.vim'
Plug 'alvan/vim-closetag'
Plug 'skammer/vim-css-color'
Plug 'hail2u/vim-css3-syntax'

" Colorschemes
Plug 'tomasr/molokai'
Plug 'morhetz/gruvbox'

call plug#end()

colorscheme gruvbox

set background=dark
set number
set tabstop=4
set shiftwidth=4
set expandtab

au FileType c set noexpandtab

map <F2> ==j100h
map <F3> gg10000<F2>
map <F4> :!make<CR>
map <F5> :!make execute<CR>
map <F6> :!make .PHONY<CR>
map <C-n> :NERDTreeToggle<CR>

let g:NERDCustomDelimiters = { 'c': { 'left': '/* ','right': ' */' } }
