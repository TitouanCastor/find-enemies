
# Find enemies

Let me guess, you enjoy playing on ATF to fight people online but you struggle to find their bases ? Let me introduce my "Find enemies" project. With this tool you can compare the dynamap each day to find where people have left blocks to easily track them down !

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
- The new map will be stored in a folder named by the two parameters you gave
- In the new folder, the map will be whiter than usual and every bloc that was different on both maps will be coloured in red

I've left two maps so you can do your own tests before trying out for real, 
have fun !

# Example

03/01/2025  :
![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/03%3A01%3A2025/chunk-1_-1.png)

04/01/2025  :
![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/04%3A01%3A2025/chunk-1_-1.png)

result      :
![alt text](https://github.com/TitouanCastor/find-enemies/blob/main/03%3A01%3A2025-04%3A01%3A2025/chunk-1_-1)