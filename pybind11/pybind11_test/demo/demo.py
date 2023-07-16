# =============================================================
# !/usr/bin/python
# -*- coding=utf-8 -*-
# Name:         demo
# Description:
# Author:       liu
# Date:         2021/3/4
# Mail:
# =============================================================

from __future__ import absolute_import
from __future__ import print_function
from __future__ import division

import sys
sys.path.append('./proto')

from demo_pb2 import TextInfo
from google.protobuf.json_format import MessageToJson
from google.protobuf.json_format import MessageToDict


text_info = TextInfo()
text_info.text1 = 'hello beijing'
text_info.text2 = 'hello shanghai'
print(text_info)
# text_info.text_sum.append('hello beijing')
# text_info.text_sum.append('hello shanghai')
#
# print('text_info type is %s' % type(text_info))
# print(text_info)
#
# text_info_json = MessageToJson(text_info)  # 把pb 转换成字符串 json
# print('text_info_json type is %s' % type(text_info_json))
# print(text_info_json)
#
# text_info_dict = MessageToDict(text_info)  # 把pb 转换成dict
# print('text_info_dict type is %s' % type(text_info_dict))
# print(text_info_dict)
