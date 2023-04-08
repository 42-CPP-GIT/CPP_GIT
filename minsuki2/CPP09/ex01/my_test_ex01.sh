echo "< Subject >"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
echo

echo "< Self Test >"
./RPN "5   6 + 4 2 / 23 3098+/31+*243/---+-/+4/"
echo


echo "< Empty >"
./RPN ""
./RPN "                     "
echo

echo "< Wrong cnt >"
./RPN "1++"
./RPN "1+1+"
./RPN "++"
./RPN "+"
./RPN "1++        "
./RPN "       1+1+"
./RPN "+           +"
./RPN "1+      +        "
./RPN "            +        "
echo

echo "< Wrong eqn >"
./RPN "1+11+"
./RPN "1+1"
./RPN "++1111+"
./RPN "+1+111+"

./RPN "  1       +       1       1              +       "
./RPN "1       +       1       "
./RPN "+       +1       1       11       +"
./RPN "   +1+   11           1   +"

./RPN "5   6 + 4 ++444++23 / 23 3098+/31+*243/---+-/+4/"





