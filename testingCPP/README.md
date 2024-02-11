# CPP testing folder

## casting types :
* static_cast :
<h2>Syntax :</h2>
        ```static_cast <dest_type> (source);```

<p>
	This is the simplest type of cast that can be used. It is a compile-time cast. 
	It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions.
</p>

* * static_cast to Cast ‘to and from’ Void Pointer
	static_cast operator allows casting from any pointer type to void pointer and vice versa.
+ notes
/*
	the static cast is good to use if the type casted is a primetive data type with no pointers , 
	if pointers it only works if the one casted are already the same datatype(hhh no aim to do so)
*/