# 名侦探柯南——区间套定理
## 题目描述

故事发生在2015年9月份的某天。

《名探偵コナン》（中文：名侦探柯南）第19部剧场版《业火的向日葵》将于2015.10.23在大陆上映。“蔡国庆”三人组决定去买首映票一睹为快。（什么？你不知道“蔡国庆”三人组有谁？蔡导、国导、庆导嘛 :)  )

龙哥是狂热的柯南粉，毕竟这是他在追的唯一一部日漫。但是首映票只剩三张了，龙哥不愿让“蔡国庆”“独吞”了首映票，决定和他们一决高下，只要“蔡国庆”能回答出龙哥出的三道题，就算获胜，否则失败。

“第一题：工藤新一是被谁灌了什么药变小的？”

蔡导：“被琴酒灌下了APTX4869。”

“正确。第二题：Link-Cut-Tree每次操作的均摊时间复杂度是？”

国导（又名程导）：“O(logn).”

又正确了，龙哥只剩下一次出题机会了。他绞尽脑汁，突然回光返照，哦不，是灵光一现。

“最近学了闭区间套定理，如果{[an,bn]}形成一个闭区间套，则在实数系中存在唯一的实数ξ属于所有的闭区间[an,bn].”

“现在有一个类似的问题：有一个整数ξ，有N个人，每个人描述这个数存在某个区间中，他们中有x个人说了真话（即ξ在描述的这个区间中），有N-x个人说了真话（即ξ不在描述的这个区间中），请求出ξ的值。”

庆导尝试了各种数据结构和算法也不能实现QAQ，便来指责出题人。龙哥为了赢得最终的胜利和票子，特来邀请你帮他检验可行性，事成之后他会将三张票之一送你，至于另一张嘛你懂得~（喂！龙哥明明单身╮(╯﹏╰)╭）

## 输入描述

第一行包含2个整数N，x，表示有N个人，其中有x个人说了真话，N-x个人说了假话。

接下来N行，每行一个区间，每个区间包含且仅包含两个由逗号隔开的整数，一个(或[，以及一个)或]，所以有四种可能的区间，详见样例输入。保证区间合法。

## 输出描述

仅一个整数ξ，含义如题所示，保证答案唯一，不要输出多余的空格和换行，这样出题不能保证你能通过，喵呜~。保证0<=ξ<=1000000

## 样例输入

	4 4
	(1,3)
	(1,3]
	[1,3)
	[1,3]

## 样例输出

	2

## 注释

对于100%的数据 0<x<=N<=20