CREATE TABLE PersonalInfo(
    name char(10) not null,
    id char(10) not null,
    passwd char(10) not null,
    PRIMARY KEY (id)
);

CREATE TABLE Msg(
    id char(10) not null,
    opp_id char(10) not null,
    text_msg char(20) not null,
    msg_time timestamp not null,
    FOREIGN KEY(id) REFERENCES PersonalInfo(id),
    FOREIGN KEY(opp_id) REFERENCES PersonalInfo(id)
);