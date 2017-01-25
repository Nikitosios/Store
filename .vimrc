call plug#begin('~/.vim/plugged/')

Plug 'Shougo/neocomplcache.vim'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'python-mode/python-mode'
Plug 'scrooloose/nerdtree', { 'on' : 'NERDTreeToggle' }
Plug 'jiangmiao/auto-pairs'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'ctrlpvim/ctrlp.vim'

" Colorschemes
Plug 'tomasr/molokai'
Plug 'morhetz/gruvbox'

call plug#end()


filetype plugin indent on
syntax on
colorscheme molokai

set background=dark
set number
set tabstop=4
set shiftwidth=4
set noexpandtab

augroup project
	autocmd!
	autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
augroup END

let &path.="src/include,/usr/include/AL,src,"

map <F4> 1000<F6>
map <F5> :!make \|\| gcc -Wall -o $(basename pwd) $(find . -type f -name main.c* -print)<CR>
map <F6> ==j100h
map <F7> :!./$(find . -type f -executable -print)<CR>
au FileType python map <F7> :!python `find . -name main.py -print`<CR>
map <F8> :!make \|\| gcc -Wall -o $(basename pwd) $(find . -type f -name main.c* -print)<CR>:!./$(find . -type f -executable -print)<CR>
map <C-n> :NERDTreeToggle<CR>

filetype indent plugin on
au FileType python set expandtab

let g:neocomplcache_enable_at_startup = 1

let g:cpp_class_scope_highlight = 1
let g:cpp_experimental_simple_template_highlight = 1
let g:cpp_concepts_highlight = 1

let g:pymode_python = 'python3'
let g:pymode_syntax_all = 1
let g:pymode_folding = 0
let g:pymode_lint = 0
