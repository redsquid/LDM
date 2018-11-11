set exrc
set secure

set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

set colorcolumn=110
highlight ColorColumn ctermbg=darkgray

let &path.="src/,"

let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/YouCompleteMe/.ycm_extra_conf.py"

autocmd vimenter * NERDTree

nnoremap <F4> :make!<cr>
nnoremap <F5> :!./main<cr>




nmap <F2> :NERDTreeToggle<CR>
map  <Tab> <C-W>W
