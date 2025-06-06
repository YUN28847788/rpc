#include <iostream>
#include <string>
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include "friend.pb.h"

class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout<<"do GetFriendsList service!"<<std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liang yun");
        vec.push_back("wang yang");

        return vec;
    }
    //重写基类方法

    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::fixbug::GetFriendsListRequest *request,
                       ::fixbug::GetFriendsListResponse *response,
                       ::google::protobuf::Closure *done)
    {
        uint32_t userid = request->userid();

        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        response->add_friends();
        for(std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();

    }
};

int main(int argc,char **argv)
{
        //调用框架的初始化操作

    MprpcApplication::Init(argc, argv);

    //provider 是一个rpc网络服务对象
    //把UserService对象发布到rpc节点上
    RpcProvider provider;

    provider.NotifyService(new FriendService());
    
    //启动一个rpc服务发布节点 run以后 进程进入阻塞状态 等待远程rpc调用请求
    provider.Run();

    return 0;
}
