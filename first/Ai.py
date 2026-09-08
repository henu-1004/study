import numpy as np
import json
import re
import string

import tensorflow as tf
from tensorflow.keras import layers, models, callbacks, losses

VOCAB_SIZE = 10000
MAX_LEN = 200
EMBEDDING_DIM = 100
N_UNITS = 128
VALIDATION_SPLIT = 0.2
SEED = 42
LOAD_MODEL = False
BATCH_SIZE = 32
EPOCHS = 25

# 전체 데이터셋 로드
with open("kaggle.json") as json_data:
    recipe_data = json.load(json_data)

    # 데이터셋 필터링
filtered_data = [
    "Recipe for " + x["title"] + " | " + " ".join(x["directions"])
    for x in recipe_data
    if "title" in x
    and x["title"] is not None
    and "directions" in x
    and x["directions"] is not None
]

# 레시피 개수 확인
n_recipes = len(filtered_data)
print(f"{n_recipes}개 레시피 로드")
print(filtered_data)
example = filtered_data[9]
print(example)