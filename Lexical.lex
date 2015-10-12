/* 
 * Sample Scanner2: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D twice!
 */

	int num_lines = 0, num_chars = 0, num_zhus = 0;

%%
\n	++num_lines; ++num_chars;
.	++num_chars;
zhu ++num_zhus;
%%

main()
{
  yylex();
  printf("\n# total lines = %d\ttotal chars = %d\ttotal zhus = %d\n", num_lines, num_chars, num_zhus);
}
