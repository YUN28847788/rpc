

# aux_source_directory(. SRC_LIST)
set(SRC_LIST 
mprpcapplication.cc 
mprpcconfig.cc 
rpcheader.pb.cc 
rpcprovider.cc 
mprpcchannel.cc 
mprpccontroller.cc 
logger.cc)
add_library(mprpc ${SRC_LIST})##SHARED 动态库
target_link_libraries(mprpc muduo_net muduo_base pthread)