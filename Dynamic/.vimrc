set exrc
set secure

set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set number

set colorcolumn=110
highlight ColorColumn ctermbg=darkgray

let &path.=":src/:../lib/ldmtest/include/"

let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/YouCompleteMe/.ycm_extra_conf.py"

autocmd vimenter * NERDTree

nnoremap <F4> :make!<cr>
nnoremap <F5> :!./main<cr>




nmap <F12> :NERDTreeToggle<cr>
nmap <F2> :wa<cr>
nmap <F3> :FSHere<cr>
map  <Tab> <C-W>W
map<C-Right> :bn<cr>
map<C-Left> :bp<cr>
