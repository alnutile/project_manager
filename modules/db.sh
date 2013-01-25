#!/bin/sh
mysqldump -uroot -p --database d8 > db.sql
tar czvf db.sql.tar.gz db.sql
rm db.sql
