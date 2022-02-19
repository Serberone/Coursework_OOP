drop database kurs;

create database if not exists kurs;

use kurs;

create table if not exists genre (
g_name varchar(255) not null unique primary key
);

create table if not exists author (
author varchar(255) not null unique primary key
);

create table if not exists publisher (
publisher varchar(255) not null unique primary key
);

create table if not exists user_ (
 UserId int not null auto_increment unique primary key,
 login varchar(255) not null unique,
 password_ varchar(255) not null,
 email varchar(255) not null
);

insert into user_(login, password_, email) values ("admin", "admin", "admin@gmail.com");
insert into user_(login, password_, email) values ("Сергей", "1234", "ser@gmail.com");
insert into genre(g_name) values ("Супергерои"), ("Экшен");
insert into author(author) values ("Стэн Ли"), ("Сэм Лью");
insert into publisher(publisher) values ("Истари Комикc"), ("Marvel");

create table if not exists comix (
ComixId int not null auto_increment unique primary key,
title varchar(255) not null unique,
numb_of_ch int,
stat varchar(255) not null,
translate varchar(255),
descript varchar(255),
g_name varchar(255) not null,
constraint genre_fk
foreign key (g_name) references genre (g_name),
author varchar(255) not null,
constraint auth_fk
foreign key (author) references author (author),
publisher varchar(255) not null,
constraint pub_fk
foreign key (publisher) references publisher (publisher)
);

insert into comix(title, numb_of_ch, stat, translate, descript, g_name, author, publisher)
values ("Новый Человек-Паук", 6, "Закончено", "Английский", "Хит 2012 года!", "Супергерои", "Стэн Ли", "Истари Комикc"),
("Бэтмен против Джокера", 24, "Продолжается", "Русский", "Эпичное противостояние!", "Экшен", "Сэм Лью", "Marvel"),
("Тор", 14, "Закончено", "Русский", "Начало истории Повелителя Грома", "Экшен", "Стэн Ли", "Marvel");