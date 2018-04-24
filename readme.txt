This is the readme file for our software- Publication Management
Final release.
Platform tested: Windows 10

How to use:
The finished product is supplied as a zip file which can be extracted and the software can be used by running the executable "Pub.exe".
It can be run by simply double clicking on it or by using Command Prompt. It does not require preinstalled C++ compiler and all neccessary files are contained within the software package.
Other way is using Cygwin software on windows and just execute makefile.

Note: All data files need to be in the same folder as executable files(code).

Features included:
There are 2 types of users- Guest and Admin
Guest users have access to searching, statistics and news facilities.
Admin users have access to editing in addition to the facilities provided to guest user.

Login:
Enter your username and password when prompted. If it matches any credentials in the database, you will be logged in successfully.

Registration:
As the software is designed to be used on a small scale, we have NOT included any explicit option for registration. The software owner can manually add or remove credentials from the database by using any simple text editor such as Notepad. Use the following format to add credentials in "data\admin.txt":
"username, password" without the inverted commas
Keep all credentials on separate lines and do not leave blank lines.
As the files are not encrypted, it is responsibility of the system owner to ensure that users are well-behaved and do not misuse these files.

Search:
This function is available to all users.
There are five types of search- paper name, author name, journal name, year published and DOI.
Enter whole or part of the names, but for year or DOI you need to give complete input.
Results are displayed as a list of bibliographies of matching papers.

Statistics:
This function is available to all users.
You can get the statistics sorted by either year or author.
Results are displayed as a list of the years/authors along with number of papers belonging to each.

News:
All saved changes done by admin users are recorded in a log file. Users can request to view the activities performed by the admins to get the latest updates. The entire activity log is displayed with most recent entries at the bottom.
If required, the system owner can clear the log file manually by deleting the contents of file "data\activitylog.txt" using a text editor such as Notepad.

Edit:
This function is available only to logged in Admin users.
They can add, delete or modify papers. Be careful to use only the IEEE format, which is also displayed at the top of the console when running the software. By extension, they also have access to save and roll back options.
Until the data is saved, it is only in the running memory. Therefore, if the program is shut down incorrectly all unsaved changes are lost.
By saving, the entire updated data is written into the data file. Rolling back allows the user to discard any unsaved changes and reloads the last saved data from the file into the memory.
