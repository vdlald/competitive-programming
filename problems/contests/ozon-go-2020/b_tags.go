package main

import (
	"bufio"
	"os"

	"database/sql"
	"fmt"
	_ "github.com/mattn/go-sqlite3"
)

func main() {
	//db, _ := sql.Open("sqlite3", "./db.db")
	db, _ := sql.Open("sqlite3", "./temp.db")

	inputSql, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	prepare, _ := db.Prepare(inputSql)
	_, _ = prepare.Exec()

	rows, err := db.Query(
		"SELECT goods.id, goods.name FROM goods LEFT OUTER JOIN tags_goods ON goods.id = tags_goods.goods_id GROUP by goods.name HAVING count(goods.name) = (SELECT count(*) FROM tags)")
	if err != nil {
		print(err)
	}

	var id int

	var name string

	for rows.Next() {
		_ = rows.Scan(&id, &name)
		fmt.Printf("%d %s\n", id, name)
	}
}
