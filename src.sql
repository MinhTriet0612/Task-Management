create table task
(
    id        int          not null auto_increment
        primary key,
    status    varchar(50)  not null,
    priority  varchar(50)  not null,
    startDate date         not null,
    deadline  date         not null,
    user_id   int          not null,
    note      varchar(255) null,
    title     varchar(255) null,
    constraint task_ibfk_1
        foreign key (user_id) references user (id)
);

create index user_id
    on task (user_id);


create table user
(
    id       int auto_increment
        primary key,
    username varchar(50) not null,
    password varchar(50) not null
);