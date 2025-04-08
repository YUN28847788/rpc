#include "test.pb.h"
#include <iostream>
#include <string>

using namespace fixbug;


int main()
{
    LoginResponse rsp;
    ResultCode *rc = rsp.mutable_result();

    rc->set_errcode(1);
    rc->set_errmsg("登录处理失败了");
    

    return 0;
}

int main1()
{
    //封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    //对象数据序列化 =>char *

    std::string send_str;
    if(req.SerializePartialToString(&send_str))
    {
        std::cout<<send_str.c_str()<<std::endl;
    }

    //反序列化
    LoginRequest reqB;
    if(reqB.LoginRequest::ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}