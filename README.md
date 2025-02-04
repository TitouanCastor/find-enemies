
# Find enemies

Let me guess, you enjoy playing on ATF to fight people online but you struggle to find their bases ? Let me introduce my "Find enemies" project. With this tool you can compare the dynamap each day to find where people have left blocks to easily track them down !

# Usage

First things first, you have to open the main.c file to edit the 63th line, write the path to your repository, it will be useful later

You then have to download imagemagick by executing this command : "sudo apt install imagemagick"
for more information : https://github.com/ImageMagick/ImageMagick

"Find enemies" has two utilities :

- Download the dynamap and store it in a folder
- Compare the dynamap previously downloaded

First let's download the map :

- First you have to call the make rule (make / make re)
- Then you just have to execute the "find-enemies" binary
- The map will be stored in a folder named by the date of the day (in 512*512 chunks)
- Pro tip : you can use a crontab to execute this command daily

Then we have to compare these maps :

- First you have to call the make rule (make / make re)
- Then you have to execute the "find-enemies" binary followed by the name of the two folders you wan't to compare
- The new map will be stored in a folder named by the two parameters you gave
- In the new folder, the map will be whiter than usual and every bloc that was different on both maps will be coloured in red

I've left two maps so you can do your own tests before trying out for real, 
have fun !