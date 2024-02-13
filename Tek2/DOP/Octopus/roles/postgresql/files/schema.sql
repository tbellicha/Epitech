
CREATE TABLE IF NOT EXISTS votes
(
  id text PRIMARY KEY,
  vote text NOT NULL
);

CREATE TABLE IF NOT EXISTS paul
(
  id text PRIMARY KEY,
  username text NOT NULL,
  pass text NOT NULL
);
