#!/bin/bash
lex lexl_looper.l
yacc -d yass.y -v
gcc -w -g y.tab.c -ly -ll -o parser
