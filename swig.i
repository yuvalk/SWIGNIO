/* File : Swig.i */
%module(directors="1") example

%include "std_string.i"
%include "typemaps.i"

%include "enumtypeunsafe.swg"
%javaconst(1);

//define new typemap
     %typemap(jni) unsigned char* BUFFER "jobject"
     %typemap(jtype) unsigned char* BUFFER "java.nio.ByteBuffer"
     %typemap(jstype) unsigned char* BUFFER "java.nio.ByteBuffer"
     %typemap(javain,
           pre="    assert $javainput.isDirect() : \"Buffer must be allocated direct.\";") unsigned char* BUFFER "$javainput"
     %typemap(javaout) unsigned char* BUFFER {
         return $jnicall;
     }
     %typemap(in) unsigned char* BUFFER {
       $1 = (unsigned char*) jenv->GetDirectBufferAddress($input);
       if ($1 == NULL) {
         SWIG_JavaThrowException(jenv, SWIG_JavaRuntimeException, "Unable to get address of direct buffer. Buffer must be allocated direct.");
       }
     }
     %typemap(memberin) unsigned char* BUFFER {
       if ($input) {
         $1 = $input;
       } else {
         $1 = 0;
       }
     }
     %typemap(freearg) unsigned char* BUFFER ""
//define end

    %apply unsigned char* BUFFER {unsigned char* image_buffer}

%{
  #include "interface.h"
%}

/* turn on director wrapping Callback */
%feature("director") IFrameCB;

/* Let's just grab the original header file here */
%include "interface.h"
