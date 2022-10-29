#! /bin/bash

./megaphone "shhhhh... I think the students are asleep..." > my.txt
./megaphone Damnit " ! " "Sorry students, I thought this thing was off." >> my.txt
./megaphone >> my.txt
# cat my.txt
diff ans.txt my.txt
