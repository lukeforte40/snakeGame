This project is on development of the game snake. The purpose of this game is to expand my c++ skills and practice.
Specifically I will practise executing a project structure that is scalable for larger projects as it begins getting more complicated. Additionally I began to explore the use of custom code snippets in vs code, specifically boilerplate code for c++.
Project Structure:
Bin: A folder that contains the compiled .DLL file or (sometimes) a .lib or the executable application or .exe file — the “binary”.
Include: A folder that contains the publicly distributed .h (header files) for a library to be included in another application, required to use a library or DLL.
Lib: A folder that contains statically linkable ,lib files (precompiled code) and is part of a library.
Doc: All those nifty manuals programmers hate to write, or generated ones from the output of a source documentation utility like Doxygen, or a README file, or the .man files for Linux “man” command, or an offline website so you would see .html files.
Build: a folder that is sometimes there for holding onto build scripts, half-built code, other stuff related to the compilation process, usually its generated by a utility or the compiler, you might see .objs here but you might not. There are other names for this folder on each platform, and sometimes you might find online documentation describing its structure, like for Android.
Src: This is where the source code is, people edit this stuff, and it may have sub-folders.
Data: Some applications come with “sample data” or “test data” that usually sits in here and is accessed by the application in the bin/ folder.
Examples: Some libraries come with a set of applications that test out various “units” of the “system” and also demonstrate usage. aka unitTests