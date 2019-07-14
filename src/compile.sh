SRC="stack_gen.c check_stack.c instructions_swap.c instructions_push.c instructions_rotate.c
instructions_rrotate.c actions.c read_inst.c error.c exe.c track.c execute.c help.c descent.c
descent_action.c climb.c print_module.c print_module2.c startfinish_rotate.c"
gcc push_swap.c  $SRC libftprinf/libftprintf.a -I libftprinf/includes -g
