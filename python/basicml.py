#! /usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import (division, absolute_import, print_function,
                        unicode_literals)
from sklearn import tree


def main():

    # features = [[155, "rough"], [180, "rough"], [135, "smooth"],
    # [110, "smooth"], etc]  # Input to classifier
    features = [[155, 0], [180, 0], [135, 1], [110, 1], [300, 0], [320, 0],
                [350, 1], [380, 1]]  # scikit-learn requires real-valued features

    # labels = ["orange", "orange", "apple", "apple", "melon", "melon",
    # "watermelon", "watermelon"]  # output values
    labels = ['🍊', '🍊', '🍎', '🍎', '🍈', '🍈', '🍉', '🍉']

    # Training classifier
    classifier = tree.DecisionTreeClassifier()  # using decision tree classifier
    classifier = classifier.fit(features, labels)  # Find patterns in data

    # Making predictions
    result = classifier.predict([[120, 1]])

    # Output is apple
    print(result[0])


if __name__ == '__main__':
    main()
