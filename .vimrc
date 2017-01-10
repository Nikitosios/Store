call plug#begin('~/.vim/plugged/')
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Valloric/YouCompleteMe'
Plug 'jiangmiao/auto-pairs'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'morhetz/gruvbox'
call plug#end()
syntax on
colorscheme gruvbox
set background=dark
set number
set softtabstop=4
set tabstop=4
set shiftwidth=4
set noexpandtab
map <F5> :!make<CR>
map <F7> :!make<CR>:!./
map <F6> ==j100h
map <F4> 1000<F6>
map <F9> :!make<CR>:!./<Up><CR>
map <C-n> :NERDTreeToggle<CR>
