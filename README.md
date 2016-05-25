# cxs
A C++ Compatible Language

A refinement on modern C++ that utilizes 100% C++ compatibility as a glue to the past, and frees us to try something new. Other languages have tried different approaches, this is my (hopefully someday our) approach as a *pramattic engineer*. I spend my days working in legacy code bases while keeping up on modern advancements and trends towards functional programming. That said we are the tiniest of ant standing on the largest of shoulders, and bring in many perspectives explored by others (often through extensive/expensive trial and error). Many opportunitities are lost and teams are not only stuck with interoping with existing code, but existing engineers.

A hypothetical coworker, McKinney, has been working at your company for over 30 years. His first 20 years were spent writing device drivers and kernel module's in C, and the next 10 learning C++. McKinney isn't alone at your company, he's only one of hundreds of engineers or supposed contactors who have worked on the same code base you need to make a living in. It may seem like there's no way out. It'

Can't rewrite the language in Rust. Can't do it in D, **won't regress it back to C**, enjoy modern c++ features, but still believe the boilerplate in working with C++ is too troublesome.

It's okay though, your job only requires you to occasionally fix bugs in the existing infrastructure, your *real work* is new code you'll be adding as a new module. Your new module will need to link with and use shared libraries with the existing code base, and it has to be just as fast as the other modules. Can't write it in some other runtime-based language, and integrating a whole new language is far too much of a dependency nightmare. If you want to write modern code that resembles both python and C++, that is guaranteed to compile down to the same c++ code your familiar with, and is essentially an extension library for your c++ compiler, than cxs is perfect for you.

cxs is both a compiler and an interpreter, and can be run as both. cxs can be ran as a script that utilizes a *almost non-existant* runtime (initialization-time statically checked), or compiled (statically checked) want a binary to *process all of our personal data* that makes zero-overhead function calls into existing legacy C and C++ code bases.

= Features
+ Completely fluid integration with c++, compiles c++ TLU's and binary's without modification.
+ - inline cxs or c++ code blocks, depending on which mode your compiling the file for.

* EXAMPLES
*- Here is an example inline **c++ block**
# somefile.cxs
 
 ...
 # Here is a one line inline C++ code block (not sure how useful in practice)!
 c++ block {
   #include <iostream>
   
   void hello() { std::cout << "Hello world !!"; }
   
   void cxs_entry() { hello(); }
 }
   #include <myfavoritecpplibrary> myfavlib::dosomething(cxs_var);
   std::cout << "result from my lib is '" << cxs_var }
