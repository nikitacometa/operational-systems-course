.code64

#define newHandler(n) \
handler##n:           \
	pushq $0;         \
	pushq $n;         \
	jmp handling      \


#define newErrHandler(n) \
handler##n:              \
	pushq $n;            \
	jmp handling         \


newHandler(0)
newHandler(1)
newHandler(2)
newHandler(3)
newHandler(4)
newHandler(5)
newHandler(6)
newHandler(7)
newErrHandler(8)
newHandler(9)
newErrHandler(10)
newErrHandler(11)
newErrHandler(12)
newErrHandler(13)
newErrHandler(14)
newHandler(15)
newHandler(16)
newErrHandler(17)
newHandler(18)
newHandler(19)
newHandler(20)
newHandler(21)
newHandler(22)
newHandler(23)
newHandler(24)
newHandler(25)
newHandler(26)
newHandler(27)
newHandler(28)
newHandler(29)
newHandler(30)
newHandler(31)
newHandler(32)
newHandler(33)
newHandler(34)
newHandler(35)
newHandler(36)
newHandler(37)
newHandler(38)
newHandler(39)
newHandler(40)
newHandler(41)
newHandler(42)
newHandler(43)
newHandler(44)
newHandler(45)
newHandler(46)
newHandler(47)
newHandler(48)
newHandler(49)
newHandler(50)
newHandler(51)
newHandler(52)
newHandler(53)
newHandler(54)
newHandler(55)
newHandler(56)
newHandler(57)
newHandler(58)
newHandler(59)
newHandler(60)
newHandler(61)
newHandler(62)
newHandler(63)
newHandler(64)
newHandler(65)
newHandler(66)
newHandler(67)
newHandler(68)
newHandler(69)
newHandler(70)
newHandler(71)
newHandler(72)
newHandler(73)
newHandler(74)
newHandler(75)
newHandler(76)
newHandler(77)
newHandler(78)
newHandler(79)
newHandler(80)
newHandler(81)
newHandler(82)
newHandler(83)
newHandler(84)
newHandler(85)
newHandler(86)
newHandler(87)
newHandler(88)
newHandler(89)
newHandler(90)
newHandler(91)
newHandler(92)
newHandler(93)
newHandler(94)
newHandler(95)
newHandler(96)
newHandler(97)
newHandler(98)
newHandler(99)
newHandler(100)
newHandler(101)
newHandler(102)
newHandler(103)
newHandler(104)
newHandler(105)
newHandler(106)
newHandler(107)
newHandler(108)
newHandler(109)
newHandler(110)
newHandler(111)
newHandler(112)
newHandler(113)
newHandler(114)
newHandler(115)
newHandler(116)
newHandler(117)
newHandler(118)
newHandler(119)
newHandler(120)
newHandler(121)
newHandler(122)
newHandler(123)
newHandler(124)
newHandler(125)
newHandler(126)
newHandler(127)
newHandler(128)
newHandler(129)
newHandler(130)
newHandler(131)
newHandler(132)
newHandler(133)
newHandler(134)
newHandler(135)
newHandler(136)
newHandler(137)
newHandler(138)
newHandler(139)
newHandler(140)
newHandler(141)
newHandler(142)
newHandler(143)
newHandler(144)
newHandler(145)
newHandler(146)
newHandler(147)
newHandler(148)
newHandler(149)
newHandler(150)
newHandler(151)
newHandler(152)
newHandler(153)
newHandler(154)
newHandler(155)
newHandler(156)
newHandler(157)
newHandler(158)
newHandler(159)
newHandler(160)
newHandler(161)
newHandler(162)
newHandler(163)
newHandler(164)
newHandler(165)
newHandler(166)
newHandler(167)
newHandler(168)
newHandler(169)
newHandler(170)
newHandler(171)
newHandler(172)
newHandler(173)
newHandler(174)
newHandler(175)
newHandler(176)
newHandler(177)
newHandler(178)
newHandler(179)
newHandler(180)
newHandler(181)
newHandler(182)
newHandler(183)
newHandler(184)
newHandler(185)
newHandler(186)
newHandler(187)
newHandler(188)
newHandler(189)
newHandler(190)
newHandler(191)
newHandler(192)
newHandler(193)
newHandler(194)
newHandler(195)
newHandler(196)
newHandler(197)
newHandler(198)
newHandler(199)
newHandler(200)
newHandler(201)
newHandler(202)
newHandler(203)
newHandler(204)
newHandler(205)
newHandler(206)
newHandler(207)
newHandler(208)
newHandler(209)
newHandler(210)
newHandler(211)
newHandler(212)
newHandler(213)
newHandler(214)
newHandler(215)
newHandler(216)
newHandler(217)
newHandler(218)
newHandler(219)
newHandler(220)
newHandler(221)
newHandler(222)
newHandler(223)
newHandler(224)
newHandler(225)
newHandler(226)
newHandler(227)
newHandler(228)
newHandler(229)
newHandler(230)
newHandler(231)
newHandler(232)
newHandler(233)
newHandler(234)
newHandler(235)
newHandler(236)
newHandler(237)
newHandler(238)
newHandler(239)
newHandler(240)
newHandler(241)
newHandler(242)
newHandler(243)
newHandler(244)
newHandler(245)
newHandler(246)
newHandler(247)
newHandler(248)
newHandler(249)
newHandler(250)
newHandler(251)
newHandler(252)
newHandler(253)
newHandler(254)
newHandler(255)


.global handlers

handlers:
	.quad handler0
	.quad handler1
	.quad handler2
	.quad handler3
	.quad handler4
	.quad handler5
	.quad handler6
	.quad handler7
	.quad handler8
	.quad handler9
	.quad handler10
	.quad handler11
	.quad handler12
	.quad handler13
	.quad handler14
	.quad handler15
	.quad handler16
	.quad handler17
	.quad handler18
	.quad handler19
	.quad handler20
	.quad handler21
	.quad handler22
	.quad handler23
	.quad handler24
	.quad handler25
	.quad handler26
	.quad handler27
	.quad handler28
	.quad handler29
	.quad handler30
	.quad handler31
	.quad handler32
	.quad handler33
	.quad handler34
	.quad handler35
	.quad handler36
	.quad handler37
	.quad handler38
	.quad handler39
	.quad handler40
	.quad handler41
	.quad handler42
	.quad handler43
	.quad handler44
	.quad handler45
	.quad handler46
	.quad handler47
	.quad handler48
	.quad handler49
	.quad handler50
	.quad handler51
	.quad handler52
	.quad handler53
	.quad handler54
	.quad handler55
	.quad handler56
	.quad handler57
	.quad handler58
	.quad handler59
	.quad handler60
	.quad handler61
	.quad handler62
	.quad handler63
	.quad handler64
	.quad handler65
	.quad handler66
	.quad handler67
	.quad handler68
	.quad handler69
	.quad handler70
	.quad handler71
	.quad handler72
	.quad handler73
	.quad handler74
	.quad handler75
	.quad handler76
	.quad handler77
	.quad handler78
	.quad handler79
	.quad handler80
	.quad handler81
	.quad handler82
	.quad handler83
	.quad handler84
	.quad handler85
	.quad handler86
	.quad handler87
	.quad handler88
	.quad handler89
	.quad handler90
	.quad handler91
	.quad handler92
	.quad handler93
	.quad handler94
	.quad handler95
	.quad handler96
	.quad handler97
	.quad handler98
	.quad handler99
	.quad handler100
	.quad handler101
	.quad handler102
	.quad handler103
	.quad handler104
	.quad handler105
	.quad handler106
	.quad handler107
	.quad handler108
	.quad handler109
	.quad handler110
	.quad handler111
	.quad handler112
	.quad handler113
	.quad handler114
	.quad handler115
	.quad handler116
	.quad handler117
	.quad handler118
	.quad handler119
	.quad handler120
	.quad handler121
	.quad handler122
	.quad handler123
	.quad handler124
	.quad handler125
	.quad handler126
	.quad handler127
	.quad handler128
	.quad handler129
	.quad handler130
	.quad handler131
	.quad handler132
	.quad handler133
	.quad handler134
	.quad handler135
	.quad handler136
	.quad handler137
	.quad handler138
	.quad handler139
	.quad handler140
	.quad handler141
	.quad handler142
	.quad handler143
	.quad handler144
	.quad handler145
	.quad handler146
	.quad handler147
	.quad handler148
	.quad handler149
	.quad handler150
	.quad handler151
	.quad handler152
	.quad handler153
	.quad handler154
	.quad handler155
	.quad handler156
	.quad handler157
	.quad handler158
	.quad handler159
	.quad handler160
	.quad handler161
	.quad handler162
	.quad handler163
	.quad handler164
	.quad handler165
	.quad handler166
	.quad handler167
	.quad handler168
	.quad handler169
	.quad handler170
	.quad handler171
	.quad handler172
	.quad handler173
	.quad handler174
	.quad handler175
	.quad handler176
	.quad handler177
	.quad handler178
	.quad handler179
	.quad handler180
	.quad handler181
	.quad handler182
	.quad handler183
	.quad handler184
	.quad handler185
	.quad handler186
	.quad handler187
	.quad handler188
	.quad handler189
	.quad handler190
	.quad handler191
	.quad handler192
	.quad handler193
	.quad handler194
	.quad handler195
	.quad handler196
	.quad handler197
	.quad handler198
	.quad handler199
	.quad handler200
	.quad handler201
	.quad handler202
	.quad handler203
	.quad handler204
	.quad handler205
	.quad handler206
	.quad handler207
	.quad handler208
	.quad handler209
	.quad handler210
	.quad handler211
	.quad handler212
	.quad handler213
	.quad handler214
	.quad handler215
	.quad handler216
	.quad handler217
	.quad handler218
	.quad handler219
	.quad handler220
	.quad handler221
	.quad handler222
	.quad handler223
	.quad handler224
	.quad handler225
	.quad handler226
	.quad handler227
	.quad handler228
	.quad handler229
	.quad handler230
	.quad handler231
	.quad handler232
	.quad handler233
	.quad handler234
	.quad handler235
	.quad handler236
	.quad handler237
	.quad handler238
	.quad handler239
	.quad handler240
	.quad handler241
	.quad handler242
	.quad handler243
	.quad handler244
	.quad handler245
	.quad handler246
	.quad handler247
	.quad handler248
	.quad handler249
	.quad handler250
	.quad handler251
	.quad handler252
	.quad handler253
	.quad handler254
	.quad handler255


handling:
	pushq %rdi
	pushq %rax
	pushq %rbx
	pushq %rcx
	pushq %rdx
	pushq %rbp
	pushq %rsi
	pushq %r8
	pushq %r9
	pushq %r10
	pushq %r11
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

	movq %rsp, %rdi 
    cld
	call handle

	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %r11
	popq %r10
	popq %r9
	popq %r8
	popq %rsi
	popq %rbp
	popq %rdx
	popq %rcx
	popq %rbx
	popq %rax
	popq %rdi

	addq $16, %rsp
	iretq