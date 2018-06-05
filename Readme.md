## How to build

* windows 

  ```shell
  mingw32-make
  ```

* linux

  ```shell
  make
  ```

## Description

* 使用bison(yacc)&flex(lex)生成concrete syntax tree
* 解析语法树，得到相关信息，调用DEGUB_*方法可以进行查看

## Data Structure about Database in MiniSQL.h

* table

  ```C++
  struct Table
  {
      string table_name;  //表名
      int attr_count;				//表中属性的总个数
      Attribute attrs[32];	//表的所有属性列表, 最多32个属性
      ...
  };
  ```

* attribute

  ```C++
  struct Attribute
  {
      string attr_name;
      int attr_type;	//属性的数据类型，分别为CHAR, FLOAT, INT
      int attr_key_type;//属性的主键类型，分别为PRIMARY, UNIQUE, NULL(EMPTY)
      int attr_len; 	//属性所存放的数据的长度，如果不是CHAR，则长度标记为1
      int attr_id;    //属性在表中是第几个
  };
  ```

* condition

  ```c++
  //	用于描述判断条件的信息
  struct Condition
  {
      string attr_name;	//条件所对应的属性名
      int attr_type;      //属性名对用的类型
      string op_type;		//条件所用到的比较模式，分别为"<>", "=", ">=", "<=", "<", ">"
      string cmp_value;	//条件所需要进行比较的值
  };
  typedef list<Condition> Condition_list;
  ```

* index

  ```C++
  //	用于描述索引信息
  struct Index
  {
      string index_name;
      string table_name;
      string attr_name;	//	索引所对应的属性
  };
  ```

* record

  ```c++
  //insert into card values("", "", 1234.4);
  struct Record
  {
      string table_name;  //表名
      vector<string> attr_values; // 要插入的值
      int num_values; //插入的字段的个数，应该与存在表的字段数相同
  };
  ```

* tuple(unused)

  ```c++
  struct Tuple: public Table
  {
      string attr_values[32];    
  };
  ```

## TODO

* API
* Record Manager
* Catalog Manager
* Index Manager
* Buffer Manger