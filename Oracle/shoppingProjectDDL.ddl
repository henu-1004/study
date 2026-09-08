-- 생성자 Oracle SQL Developer Data Modeler 24.3.1.347.1153
--   위치:        2025-08-11 16:12:32 KST
--   사이트:      Oracle Database 21c
--   유형:      Oracle Database 21c



-- predefined type, no DDL - MDSYS.SDO_GEOMETRY

-- predefined type, no DDL - XMLTYPE

CREATE TABLE cart (
    cartno        NUMBER NOT NULL,
    cartprodcount NUMBER DEFAULT 1,
    cartproddate  DATE NOT NULL,
    userid        VARCHAR2(20) NOT NULL,
    prodno        NUMBER(6) NOT NULL
);

ALTER TABLE cart ADD CONSTRAINT cart_pk PRIMARY KEY ( cartno );

CREATE TABLE category (
    cateno   NUMBER(2) NOT NULL,
    catename VARCHAR2(100) NOT NULL
);

ALTER TABLE category ADD CONSTRAINT category_pk PRIMARY KEY ( cateno );

CREATE TABLE orders (
    orderno         CHAR(11) NOT NULL,
    ordertotalprice NUMBER NOT NULL,
    orderaddress    VARCHAR2(200) NOT NULL,
    orderstatus     NUMBER DEFAULT 0,
    orderdate       DATE NOT NULL,
    userid          VARCHAR2(20) NOT NULL
);

ALTER TABLE orders ADD CONSTRAINT orders_pk PRIMARY KEY ( orderno );

CREATE TABLE ordersitem (
    itemno       NUMBER,
    itemprice    NUMBER NOT NULL,
    itemdiscount NUMBER NOT NULL,
    itemcount    NUMBER NOT NULL,
    orderno      CHAR(11) NOT NULL,
    prodno       NUMBER(6) NOT NULL
);

CREATE TABLE point (
    pointno   NUMBER NOT NULL,
    point     NUMBER NOT NULL,
    "desc"    VARCHAR2(100) NOT NULL,
    pointdate DATE NOT NULL,
    userid    VARCHAR2(20) NOT NULL
);

ALTER TABLE point ADD CONSTRAINT point_pk PRIMARY KEY ( pointno );

CREATE TABLE product (
    prodno       NUMBER(6) NOT NULL,
    prodname     VARCHAR2(20) NOT NULL,
    prodprice    NUMBER NOT NULL,
    prodstock    NUMBER,
    prodsold     NUMBER,
    proddiscount NUMBER,
    cateno       NUMBER(2) NOT NULL,
    sellerno     NUMBER
);

ALTER TABLE product ADD CONSTRAINT product_pk PRIMARY KEY ( prodno );

CREATE TABLE seller (
    sellerno NUMBER NOT NULL,
    company  VARCHAR2(100) NOT NULL,
    tel      VARCHAR2(20) NOT NULL,
    manager  VARCHAR2(20) NOT NULL,
    address  VARCHAR2(100) NOT NULL
);

ALTER TABLE seller ADD CONSTRAINT seller_pk PRIMARY KEY ( sellerno );

CREATE TABLE "User" (
    userid  VARCHAR2(20) NOT NULL,
    name    VARCHAR2(20),
    birth   CHAR(10),
    gender  CHAR(1),
    hp      CHAR(13),
    email   VARCHAR2(100),
    point   NUMBER,
    "level" NUMBER,
    address VARCHAR2(100),
    regdate DATE
);

ALTER TABLE "User" ADD CONSTRAINT user_pk PRIMARY KEY ( userid );

ALTER TABLE "User" ADD CONSTRAINT user__un UNIQUE ( hp );

ALTER TABLE "User" ADD CONSTRAINT user__unv1 UNIQUE ( email );

ALTER TABLE cart
    ADD CONSTRAINT cart_product_fk FOREIGN KEY ( prodno )
        REFERENCES product ( prodno );

ALTER TABLE cart
    ADD CONSTRAINT cart_user_fk FOREIGN KEY ( userid )
        REFERENCES "User" ( userid );

ALTER TABLE orders
    ADD CONSTRAINT orders_user_fk FOREIGN KEY ( userid )
        REFERENCES "User" ( userid );

ALTER TABLE ordersitem
    ADD CONSTRAINT ordersitem_orders_fk FOREIGN KEY ( orderno )
        REFERENCES orders ( orderno );

ALTER TABLE ordersitem
    ADD CONSTRAINT ordersitem_product_fk FOREIGN KEY ( prodno )
        REFERENCES product ( prodno );

ALTER TABLE point
    ADD CONSTRAINT point_user_fk FOREIGN KEY ( userid )
        REFERENCES "User" ( userid );

ALTER TABLE product
    ADD CONSTRAINT product_category_fk FOREIGN KEY ( cateno )
        REFERENCES category ( cateno );

ALTER TABLE product
    ADD CONSTRAINT product_seller_fk FOREIGN KEY ( sellerno )
        REFERENCES seller ( sellerno );

CREATE SEQUENCE cart_cartno_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER cart_cartno_trg BEFORE
    INSERT ON cart
    FOR EACH ROW
    WHEN ( new.cartno IS NULL )
BEGIN
    :new.cartno := cart_cartno_seq.nextval;
END;
/

CREATE SEQUENCE ordersitem_itemno_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER ordersitem_itemno_trg BEFORE
    INSERT ON ordersitem
    FOR EACH ROW
    WHEN ( new.itemno IS NULL )
BEGIN
    :new.itemno := ordersitem_itemno_seq.nextval;
END;
/

CREATE SEQUENCE point_pointno_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER point_pointno_trg BEFORE
    INSERT ON point
    FOR EACH ROW
    WHEN ( new.pointno IS NULL )
BEGIN
    :new.pointno := point_pointno_seq.nextval;
END;
/

CREATE SEQUENCE seller_sellerno_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER seller_sellerno_trg BEFORE
    INSERT ON seller
    FOR EACH ROW
    WHEN ( new.sellerno IS NULL )
BEGIN
    :new.sellerno := seller_sellerno_seq.nextval;
END;
/



-- Oracle SQL Developer Data Modeler 요약 보고서: 
-- 
-- CREATE TABLE                             8
-- CREATE INDEX                             0
-- ALTER TABLE                             17
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           4
-- ALTER TRIGGER                            0
-- CREATE COLLECTION TYPE                   0
-- CREATE STRUCTURED TYPE                   0
-- CREATE STRUCTURED TYPE BODY              0
-- CREATE CLUSTER                           0
-- CREATE CONTEXT                           0
-- CREATE DATABASE                          0
-- CREATE DIMENSION                         0
-- CREATE DIRECTORY                         0
-- CREATE DISK GROUP                        0
-- CREATE ROLE                              0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE SEQUENCE                          4
-- CREATE MATERIALIZED VIEW                 0
-- CREATE MATERIALIZED VIEW LOG             0
-- CREATE SYNONYM                           0
-- CREATE TABLESPACE                        0
-- CREATE USER                              0
-- 
-- DROP TABLESPACE                          0
-- DROP DATABASE                            0
-- 
-- REDACTION POLICY                         0
-- 
-- ORDS DROP SCHEMA                         0
-- ORDS ENABLE SCHEMA                       0
-- ORDS ENABLE OBJECT                       0
-- 
-- ERRORS                                   0
-- WARNINGS                                 0
