%% Minutes
x_label =[0.5	1	2	4	8]



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.5331	0.49866	0.47518	0.45498	0.4479	0.44248	0.43006	0.43064	0.4268	0.42342]
%y_12 = [0.40816	0.41322	0.40916	0.41626	0.42126]
%y_13 = [0.40798	0.4116	0.4154	0.4201	0.4259]
%y_14 = [0.40886	0.41162	0.41774	0.4223	0.42226]

%E[V_O]
%y_11 = [68.97297	69.344188	68.814668	69.529967	69.227642]
%y_12 = [70.062643	68.704711	67.391548	65.88535	64.35215]
%y_13 = [70.33483	68.659202	65.950893	64.403517	62.595023]
%y_14 = [70.324237	68.094298	65.161194	63.087235	62.291075]

%E[V_D]
y_11 = [191.753898	192.463612	191.562599	192.621116	192.192404]
y_12 = [192.46779	191.886452	192.552871	191.38521	190.668159]
y_13 = [192.636524	192.282227	191.546412	190.915579	189.935435]
y_14 = [192.6376	192.027614	190.785397	189.901766	190.268269]

i = i+1;
figure(i)

semilogx(x_label,y_11,'-d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_12,'--s', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_13,'--d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.1)
hold on


%ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
ylabel('E[V_D]: MB')
xlabel('E[t_2] (Unit: E[t_1])')


xticklabels({'0.5',	'1',	'2',	'4',	'8'});

												
xlim([0.5, 8]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;