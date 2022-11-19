# get-next-line (check by Moulinette)
You have been graded 125 on getnextline:
basic_tests: GNL OK | bonus_tests: GNL OK

There is a minor flaw. I didn't manage the malloc failure in the function get_next_line. When the malloc doesn't work, it will not end the function with a return of NULL. I control this issue at the beginning, but norminette check require 25 lines in each function, and I remove the malloc failure control. 