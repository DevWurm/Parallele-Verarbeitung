# error_library
A lightweight error class for C++ providing basic error storage and some output interfaces.
The library provides a class for throwing errors. You can store basic data (Error number, Error description) and
access them or put them into output streams.

##Librarys
The code is compiled in one library "liberror.a"/"liberror_windows.a", you need to add to your sources, together with the liberror.h/liberror_windows.h
header file you have to include into your source files.

##How to use
<pre><code>
#include "liberror.h" //include the header
#include <iostream>
#include <fstream>

void throw_error() {
  throw err::error(1, "Strange error"); //throw an error
}

int main() {
  std::ofstream output1("error1.log");
  std::ofstream output2("error2.log");
  
  try {
    throw_error();
  catch (error& e) {
    int code  = e.get_code() //get Error code --> 1
    std::string description = e.get_description() //get Error description --> "Strange error"
    std::string message = e.get_message() //get Error message --> "Error (1): Strange error"
    
    e.output_error() //output error message to cout
    e.output_error(output1) // output error message to output1
    
    output2 << e; //stream error to output2
  }
  
	return 0;
}
</code></pre>
It's POSSIBLE to just include the header file to your project, if you are just constructing error elements but not accessing any other member function (i.e. if you are developing a library, which is throwing error objects, but doesnt handle them), because the constructor is declared in the header file. Personally I would NOT recomend this, because you could get errors while compiling, if you forget to use no member function and in case of a library (which should be the most often case for creating but not accesing error objects) you can add the error_library source or binary and header to your library, so the user of your library can directly access error objects.

##License
Copyright 2015 DevWurm<br>
'error_library' is offered under GPL 3 License (Read ./license/gpl-3.0.txt)

##Documentation
Documentation will be offered soon. (Email me if you have any questions)

##Setup
<b>Building:</b><br>
On Windows install MinGW (components: g++, mingw32-make, ar, ranlib) and add the MinGW bin folder to your path variable
Change into the top directory of the repository and execute
<pre><code>make</code></pre>
or
<pre><code>mingw32-make</code></pre>
on Windows.
In the subfolder Binary an Object file gets compiled and in the subfolder lib a library file together with the header is
generated. The latest source is provided on <a href="https://github.com/DevWurm/error_library">GitHub</a><br><br>
<b>Using:</b><br>
Include the header file into your source file(s)
<pre><code>#include "liberror.h"</code></pre>
and add the library file to your compiling command (C++11 is required)
<pre><code>g++ your.cpp source.cpp files.cpp  <b>liberror.a</b> -std=c++11 -o ./output</code></pre>
or
<pre><code>g++ your.cpp source.cpp files.cpp  <b>liberror_windows.a</b> -std=c++11 -o .\output.exe</code></pre>
on Windows.
<br>
All the Element functions are showed in the how to use section.

##Authors
DevWurm<br>
Email: <a href='mailto:devwurm@gmx.net'>devwurm@gmx.net</a><br>
Feel free to contact me, if you have any questions or ideas about the project :)

##Collaborating
You can use the GitHub issue tracker for bugs and feature requests or create a pull request to submit 
changes and forks are welcome, too.
If you don't want to use these possibilities, you can also write me an email at 
<a href='mailto:devwurm@gmx.net'>devwurm@gmx.net</a>.
