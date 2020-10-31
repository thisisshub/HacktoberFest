# -*- coding: utf-8 -*-
"""fastAIcourse.ipynb

**Software stack**
- Fastai ( Higher level API) - a layered API
- Pytorch (flexible but not user-friendly)
- Python
"""

#hide
#skip
! [ -e /content ] && pip install -Uqq fastai  # upgrade fastai on colab

!pip install -Uqq fastbook
import fastbook
fastbook.setup_book()

from fastai.vision.all import *

path = untar_data(URLs.PETS)/'images'

def is_cat(x): return x[0].isupper()
dls = ImageDataLoaders.from_name_func(
    path, get_image_files(path), valid_pct=0.2, seed=42,
    label_func=is_cat, item_tfms=Resize(224))

learn = cnn_learner(dls, resnet34, metrics=error_rate)
learn.fine_tune(1)
