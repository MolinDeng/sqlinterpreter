#include "API.h"

bool DEBUG_Create_Table(Table& table)
{
    cout << "table_name: " << table.table_name << " ";
    cout << "attr_count: " << table.attr_count << endl;
    cout << "attr_name: " << "\t";
    for (int i = 0; i < table.attr_count; i++)
        cout << table.attrs[i].attr_name << "\t";
    cout << endl << "attr_type: " << "\t";
    for (int i = 0; i < table.attr_count; i++)
        cout << table.attrs[i].attr_type << "\t";
    cout << endl << "attr_key_type: " << "\t";
    for (int i = 0; i < table.attr_count; i++)
        cout << table.attrs[i].attr_key_type << "\t";
    cout << endl << "attr_len: " << "\t";
    for (int i = 0; i < table.attr_count; i++)
        cout << table.attrs[i].attr_len << "\t";
    cout << endl << "attr_id: " << "\t";
    for (int i = 0; i < table.attr_count; i++)
        cout << table.attrs[i].attr_id << "\t";
    cout << endl;
    return true;
}

bool DEBUG_Create_Index(Index& index)
{
    cout << "table_name: " << index.table_name << endl;
    cout << "attr_name: " << index.attr_name << endl;
    cout << "index_name: " << index.index_name << endl;
    return true;
}

bool DEBUG_Drop_Table(string table_name)
{
    cout << "table_name: " << table_name << endl;
    return true;
}


bool DEBUG_Drop_Index(string index_name)
{
    cout << "index_name: " << index_name << endl;
    return true;
}

bool DEBUG_Insert(Record& record)
{
    cout << "table_name: " << record.table_name << endl;
    cout << "values: (";
    for (auto elem : record.attr_values)
        cout << elem << ", ";
    cout << ")" << endl;
    cout << "num of values: " << record.num_values << endl;
    return true;
}

int DEBUG_Select(string table_name, Condition_list clist, bool if_where)
{
    cout << "table_name: " << table_name << endl;
    if(!if_where)
        cout << "no \'where\' clause!" << endl;
    else {
        cout << "attr_name" << "\t" << "attr_type" << "\t" << "op_type" << "\t" << "value" << "\t" << endl;
        for (auto l : clist){
            cout << l.attr_name << "\t" << l.attr_type << "\t" << l.op_type << "\t" << l.cmp_value << "\t" << endl;
        }
    }
    return 0;
}

int DEBUG_Delete(string table_name, Condition_list clist, bool if_where)
{
    cout << "table_name: " << table_name << endl;
    if(!if_where)
        cout << "no \'where\' clause!" << endl;
    else {
        cout << "attr_name" << "\t" << "attr_type" << "\t" << "op_type" << "\t" << "value" << "\t" << endl;
        for (auto l : clist){
            cout << l.attr_name << "\t" << l.attr_type << "\t" << l.op_type << "\t" << l.cmp_value << "\t" << endl;
        }
    }
    return 0;
}

/*
//	创建表时的内部调用
bool API_Create_Table(Table& table)
{}

//	删除表时的内部调用
bool API_Drop_Table(string table_name)
{}

//	创建索引时的内部调用
bool API_Create_Index(Index& index)
{}
//	删除索引时的内部调用
bool API_Drop_Index(string index_name)
{}
//	插入纪录时的内部调用
bool API_Insert(Record& record)
{}
//	选择纪录时的内部调用
int API_Select(string table_name, Condition_list clist, bool if_where)
{}
//	删除纪录时的内部调用
int API_Delete(string table_name, Condition_list clist, bool if_where)
{}

and more function
*/