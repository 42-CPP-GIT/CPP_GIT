
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


2



