" vim-plug install:
" curl -FLo ~/.vim/autoload/plug.vim --create-dirs \
" https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

call plug#begin('~/.config/nvim/plugged/')
Plug 'scrooloose/nerdtree', { 'on' : 'NERDTreeToggle' }
Plug 'scrooloose/nerdcommenter'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'jiangmiao/auto-pairs'

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

map <F2> ==j100h
map <F3> gg10000<F2>
map <F4> :!make<CR>
map <F5> :!make execute<CR>
map <F6> :!make .PHONY<CR>
map <C-n> :NERDTreeToggle<CR>

let g:NERDCustomDelimiters = { 'c': { 'left': '/* ','right': ' */' } }
