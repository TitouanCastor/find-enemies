
# Find enemies

Let me guess, you enjoy playing on ATF to fight people online but you struggle to find their bases ? Let me introduce my "Find enemies" project. With this tool you can compare the dynamap each day to find where people have left blocks to easily track them down !

# Prerequisites

To use "Find enemies" you need to download the [ImageMagick](https://github.com/ImageMagick/ImageMagick) tool by executing this command : "sudo apt install imagemagick"

# Usage

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
- The new map will be stored in a folder named by the two parameters you gave, the entire map is in the "0_map" file.
- In the new folder, the map will be whiter than usual and every bloc that was different on both maps will be coloured in red

This process can lead to errors, sometime because the map didn't download entirely but don't worry it'll still work, the map may be a little deformed tho.

I've left two maps so you can do your own tests before trying out for real, 
have fun !

# Example

05/01/2025  :

![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/screenshots/05)

06/01/2025  :

![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/screenshots/06)

result      :

![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/screenshots/chunk4_2)