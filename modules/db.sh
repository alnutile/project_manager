#!/bin/sh
mysqldump -uroot -p --database d8 > db.sql
rm db.sql
