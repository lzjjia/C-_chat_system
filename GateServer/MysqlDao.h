#pragma once
#include "const.h"  
class MySqlPool {
public:
    MySqlPool(const std::string& url, const std::string& user, 
        const std::string& pass, const std::string& schema, int poolSize);

    std::unique_ptr<sql::Connection> getConnection();

    void returnConnection(std::unique_ptr<sql::Connection> con);

    void Close();

    ~MySqlPool();

private:
    std::string url_;
    std::string user_;
    std::string pass_;
    std::string schema_;
    int poolSize_;
    std::queue<std::unique_ptr<sql::Connection>> pool_;
    std::mutex mutex_;
    std::condition_variable cond_;
    std::atomic<bool> b_stop_;
};
class MysqlDao
{
public:
    MysqlDao();
    ~MysqlDao();
    int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
    bool CheckEmail(const std::string& name, const std::string& email);
    bool UpdatePwd(const std::string& name, const std::string& newpwd);
    bool CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo);
private:
    std::unique_ptr<MySqlPool> pool_;
};

