#Apache 安全配置
---
##安装与启动
**CentOS 系类**

	yum install -y httpd


>配置文件位置
	
	/etc/httpd/conf/httpd.conf

>网站目录

	/var/www/html/

>日志位置
	
	/var/log/

>添加开机启动

	chkconfig httpd on
	
	systemctl enable httpd.service

>启动服务

	CentOS 7以下版本

	service httpd start|stop|restart
	
	CenOS 7以上版本

	 systemctl start httpd.service

##安全配置


>服务器标示隐藏

	ServerSignature Off
	ServerTokens Prod

>解释

1. ServerSignature Off’ 主要是为了让 Apache 网站服务器在所有错误页面上隐藏 Apache 版本信息。


2. ‘ServerTokens Prod’ 主要是为了在 HTTP 响应头中将服务器标记压缩到最小，否则Apache 服务器将仍然在 HTTP 回应头部包含详细的服务器标记，这会泄漏 Apache 的版本号。

>测试方法

	1.任意错误页面
	2.http数据包

>禁止列目录
>httpd.conf

_依照具体信息_

	1. Options Indexes FollowSymLinks 
	   修改为: Options  FollowSymLinks
	2. Options Indexes
	   修改为: Options None
>禁止目录访问

	<Directory /var/www/dir>
		Order Deny,Allow
		Deny from all
	</Directory>

>禁止IP访问

	<Directory /var/www/dir>
    Order Deny,Allow
    Deny from 10.1.1.2
    Allow from 192.168.1.0/255.255.255.0
	</Directory>

>禁止特定目录PHP执行

 1.

	<Directory /var/www/dir>
    	php_flag engine off
	</Directory>

 2.

	<Directory  /var/www/dir> 
		<Files  ~  ".php">
			Order  allow,deny 
			Deny  from  all 
		</Files> 
	</Directory>

 3..htaccess
 
	<Files  ~ ".php">
		order allow,deny
		deny from all
	</Files>

#MySQL
---
##安装

>安装
	
	yum install -y mysql mysql-server

>配置文件位置

	/etc/my/cnf

>启动

	service mysqld start

>其他同上

##配置

>设置默认密码

 1.

	mysqladmin -u root password 密码

 2.

	update user set password=password(‘upassword’) where user=’root’;

	flush privileges;

>删除默认数据库和数据库用户

	drop database test;

>危险语句

	local-infile=0|1

	load_file权限

1. LOAD DATA INFILE语句用于高速地从一个文本文件中读取行，并装入一个表中。这是一个很危险的内置函数，所以一般建议禁用掉（除非程序有用到本地文件）通过在my.cnf中设置

2. revoke file on *.* from 'user'@'IP'; 不要授予用户的file权限

