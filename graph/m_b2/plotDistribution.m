%% Minutes
x_label =[0.25	0.5	1	2	4	8	16	32	64	128]



%% for DeadlinMissRatio

%Miss ratio
y_11 = [0.72506	0.71386	0.69618	0.65746	0.59376	0.50862	0.4235	0.34762	0.29496	0.2683]
y_12 = [0.72328	0.71608	0.69738	0.6597	0.6003	0.51346	0.43066	0.36304	0.30542	0.27466]
y_13 = [0.7227	0.71304	0.69596	0.65566	0.59956	0.52398	0.44304	0.37186	0.31434	0.2819]
y_14 = [0.72328	0.71282	0.69578	0.65686	0.5992	0.52608	0.44936	0.37586	0.32484	0.2877]


%E[V_O]
%y_11 = [1.773549	3.473613	6.557115	12.065502	21.035704	32.219265	43.442839	52.600664	59.111303	62.440927]
%y_12 = [1.730747	3.364328	6.375511	11.690358	20.215851	31.15596	41.962157	50.739705	57.965756	61.433345]
%y_13 = [1.716923	3.323804	6.346811	11.643789	19.641123	29.849129	40.279556	49.556109	56.551478	60.738049]
%y_14 = [1.708269	3.298389	6.319243	11.507936	19.524705	29.563648	39.613828	48.658614	55.192894	59.884548]

%E[V_D]
%y_11 = [56.088902	56.880289	58.366114	61.139398	65.389004	70.345916	75.008769	78.742631	81.360326	82.509889]
%y_12 = [56.148824	56.67906	58.251072	60.947914	64.842389	69.980821	74.555736	77.949702	80.807905	82.105605]
%y_13 = [56.367132	56.909605	58.365402	61.163866	64.551853	68.93966	73.622631	77.371871	80.291859	81.819879]
%y_14 = [56.299538	56.948554	58.343655	61.091005	64.649486	68.959227	73.143014	77.076364	79.627367	81.445459]
									

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


ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
%ylabel('E[V_D]: MB')
xlabel('B_2 (Unit: Mbps)')


xticklabels({'0.25'	,'0.5'	,'1'	,'2'	,'4'	,'8'	,'16',	'32',	'64',	'128'});

												
xlim([0.25, 128]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;