export type Config = {
  categories: {
    [category: string]: {
      id: string;
      name: string;
      url: string;
    };
  };
  extension: {
    [lang: string]: string;
  };
};

export type Solve = {
  [id: string]: {
    url: string;
    name: string;
    submissions: {
      [lang: string]: string;
    };
  };
};
